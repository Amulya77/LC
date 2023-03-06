from collections import Counter
import math

def laplace_smoothing(ngram_counts, vocab_size, k=1):
    """
    Performs Laplace smoothing on a dictionary of n-gram counts.

    Args:
        ngram_counts: A dictionary mapping n-grams to their counts.
        vocab_size: The size of the vocabulary.
        k: The smoothing parameter.

    Returns:
        A dictionary mapping n-grams to their smoothed probabilities.
    """
    # Calculate the total count of all n-grams
    total_count = sum(ngram_counts.values())

    # Add k to the count of each n-gram and add k times the vocab size to the denominator
    # to account for unseen n-grams
    smoothed_counts = Counter({ngram: count + k for ngram, count in ngram_counts.items()})
    smoothed_probs = {ngram: (count / (total_count + k * vocab_size)) for ngram, count in smoothed_counts.items()}

    return smoothed_probs

  
  # Example usage
ngram_counts = Counter(["the cat sat", "the dog ran", "the cat meowed"])
vocab_size = 10
k = 1

smoothed_probs = laplace_smoothing(ngram_counts, vocab_size, k)
print(smoothed_probs)
